#include"string.h"
#include<iostream>
#include<list>
#include<fstream>
#include<algorithm>
using namespace std;
class TextEditor{
private:
    int cursor;
    int line;
    int offset;
    int total;
    int letters;
    int quots;
    int nums;
    int spaces;
    string textName;
    list<string> article;
public:
    TextEditor();
    ~TextEditor();
    const string  & getName() const;
    void setName(const string &name);
    int  getCursor(int *,int *) const;
    int moveCursor(int);
    int setCursor(int ,int);
    int addText(const string &);
    int insertText(string);
    int findTextInAll(const string &,int *,int *);
    int deleteText(const string &);
    int deleteText(int ,int,int);
    int saveFile();
    void wordState(int *,int *,int *,int *,int *) const;
    list<string>::iterator getIndex(int x);
    friend ostream & operator<<(ostream &,TextEditor &);
    friend istream & operator>>(istream &,TextEditor &);
};
TextEditor:: TextEditor(){
    textName = "Untitled";
    cursor=1;
    line=1;
    offset=0;
    total =0;
    spaces =0;
    quots =0;
    letters = 0;
    nums = 0;
}
TextEditor::~TextEditor(){
    
}
list<string>::iterator TextEditor::getIndex(int x){
    if(x<0)x=0;
    if(x>line)x=line;
    list<string>::iterator it;
    int l = 0;
    for(it=article.begin();it!=article.end();it++){
        l++;
        if(l==x) break;
    }
    return  it;
}
const string & TextEditor::getName() const{
    return textName;
}
void TextEditor::setName(const string &name){
    if(name.length()!=0){
        textName=name;
    }
}
int  TextEditor::getCursor(int * pLine=NULL,int *pOffset=NULL) const{
    *pLine = cursor;
    *pOffset=offset;
    return 1;
}
int TextEditor::moveCursor(int offset){
    list<string>::iterator it =getIndex(cursor);
    this->offset+=offset;
    while(it->length()<this->offset&&it!=article.end()){
        this->offset-=it->length();
        cursor++;
        it++;
    }
    return 1;
}
int TextEditor::setCursor(int line ,int offset){
    if(line>article.size()) line = article.size();
    this->cursor=line;
    if(offset<0) offset=0;
    if(offset>getIndex(line)->length()) offset = getIndex(line)->length();
    this->offset=offset;
    return 1;
}
int TextEditor::addText(const string & text){
    article.push_back(text);
    total+=text.length();
    for(int i=0;i<text.length();i++){
        if(text[i]==' ') spaces++;else
            if(text[i]>='0'&&text[i]<='9') nums++;else
                if(text[i]>='a'&&text[i]<='z') letters++;else
                    if(text[i]>='A'&&text[i]<='Z') letters++;else
                        quots++;
    }
    line++;
    return 1;
}
int min(int x,int y)
{
    return x<y?x:y;
}
int TextEditor::insertText(string text){
    total+=text.length();
    for(int i=0;i<text.length();i++){
        if(text[i]==' ') spaces++;else
            if(text[i]>='0'&&text[i]<='9') nums++;else
                if(text[i]>='a'&&text[i]<='z') letters++;else
                    if(text[i]>='A'&&text[i]<='Z') letters++;else
                        quots++;
    }
    if(article.empty()) {
        article.push_back(text);
        offset = text.length();
        return 1;
    }
    list<string>::iterator it = getIndex(cursor);
    
    string temp=it->substr(0,offset);
    temp+=text;
    temp +=it->substr(offset);
    *it = temp;
    return 1;
}
int TextEditor::findTextInAll(const string & text ,int *line,int *offset){
    list<string>::iterator it;
    int l=0;
    int li = *line;
    int pp = *offset;
    for(it=article.begin();it!=article.end();it++){
        l++;
        if(*line>l) continue;
        if(*line<l) *offset = -1;
        if(it->find(text,(*offset)+1)!=string::npos){
            *line = l;
            *offset = it->find(text,(*offset)+1);
            return 1;
        }
    }
    if(li==*line&&pp==*offset) *offset=-1;
    return 1;
}

int TextEditor::deleteText(const string & text){
    int line=1,offset=-1;
    findTextInAll(text,&line,&offset);
    while(1){
        if(offset==-1)break;
        cout<<"是否删除第"<<line<<"行位置"<<offset<<"处的数据(Y of N):";
        char c[100];
        cin>>c;
        if(c[0]!='Y'&&c[0]!='y') continue;
        deleteText(line,offset,text.length());
        findTextInAll(text,&line,&offset);
    }
    return 0;
}
int TextEditor::deleteText(int cursor ,int pos,int length){
    list<string>::iterator it = getIndex(cursor);
    total-=length;
    string text = *it;
    for(int i=pos;i<min(it->length(),pos+length);i++){
        if(text[i]==' ') spaces--;else
            if(text[i]>='0'&&text[i]<='9') nums--;else
                if(text[i]>='a'&&text[i]<='z') letters--;else
                    if(text[i]>='A'&&text[i]<='Z') letters--;else
                        quots--;
    }
    *it = it->erase(pos,length);
    return 0;
}
void TextEditor::wordState(int *pTotal,int *pLetter,int *pDigit,int *pSpace,int *pQuot) const{
    *pTotal = total;
    *pLetter =letters;
    *pDigit = nums;
    *pSpace =spaces;
    *pQuot = quots;
}
ostream & operator<<(ostream & out,TextEditor & editor){
    int line = 1;
    list<string>::iterator it;
    out<<"***********"<<editor.textName<<".txt*********"<<endl;
    for (it = editor.article.begin();it!=editor.article.end();it++){
        out<<line++<<":";
        out<<*it<<endl;
    }
    out<<endl;
    return out;
}
istream & operator>>(istream & in,TextEditor &editor){
    char s[100];
    getchar();
    gets(s);
    string text(s);
    editor.insertText(text);
    while(1){
        cout<<"继续输入(Y 或 N)：";
        string c;
        in>>c;
        if(c[0]!='Y'&&c[0]!='y') break;
        getchar();
        gets(s);
        string ss(s);
        editor.insertText(ss);
    }
    return in;
}
int TextEditor::saveFile(){
    string name = textName+".txt";
    ofstream out(name.c_str(),ios::out);
    list<string>::iterator it;
    for(it=article.begin();it!=article.end();it++){
        out<<*it<<endl;
    }
    out.close();
    return 0;
}

void showInstructions(){
    cout<<"*************简易文本编辑器***************\n";
    cout<<"选择以下数字进行文本编辑，请使用英文输入法"<<endl;
    cout<<"0.获取帮助信息"<<endl;
    cout<<"1.获取文档名字"<<endl;
    cout<<"2.设置文档名字"<<endl;
    cout<<"3.显示全文"<<endl;
    cout<<"4.移动光标位置"<<endl;
    cout<<"5.在光标处添加文字"<<endl;
    cout<<"6.在文档最后添加文字"<<endl;
    cout<<"7.统计文章字数"<<endl;
    cout<<"8.查找文本出现的位置"<<endl;
    cout<<"9.删除文本"<<endl;
    cout<<"10.保存文件"<<endl;
    cout<<"11.退出系统"<<endl;
    cout<<"******************************************"<<endl;
}
void getChoice(){
    TextEditor editor;
    while(1)
    {
        cout<<"\n";
        cout<<"请选择(0.显示帮助)：";
        int n;
        cin>>n;
        if(n==11) break;
        switch(n)
        {
            case 0:{
                showInstructions();
                break;
            }
            case 1:{
                cout<<"文档名称为："<<editor.getName()<<endl;
                break;
            }
            case 2:{
                string s;
                cout<<"请输入 新的文档名字: ";
                cin>>s;
                editor.setName(s);
                cout<<"设置成功"<<endl;
                break;
            }
            case 3:{
                cout<<editor;
                int line,pos;
                editor.getCursor(&line,&pos);
                cout<<"光标目前的行数为："<<line<<" 偏移量为："<<pos<<endl;
                break;
            }
            case 4:{
                int line,pos;
                editor.getCursor(&line,&pos);
                cout<<"光标目前的行数为："<<line<<" 偏移量为："<<pos<<endl;
                cout<<"光标要移动的行数:";
                cin>>line;
                cout<<"光标在这一行的位置:";
                cin>>pos;
                editor.setCursor(line,pos);
                break;
            }
            case 5:{
                cout<<editor;
                int line,pos;
                editor.getCursor(&line,&pos);
                cout<<"光标目前的行数为："<<line<<" 偏移量为："<<pos<<endl;
                string text;
                cout<<"请输入你要写入的文字(英文)："<<endl;
                cin>>editor;
                break;
            }
            case 6:{
                cout<<"请输入要添加的文字："<<endl;
                string text;
                char s[100];
                getchar();
                gets(s);
                text = s;
                editor.addText(text);
                while(1){
                    cout<<"继续插入(Y 或 N)：";
                    string c;
                    cin>>c;
                    if(c[0]!='Y'&&c[0]!='y') break;
                    getchar();
                    gets(s);
                    text = s;
                    editor.addText(text);
                }
                break;
            }
            case 7:{
                int total,space,num,quot,letter;
                editor.wordState(&total,&letter,&num,&space,&quot);
                cout<<"全文总数为："<<total<<endl;
                cout<<"全文字母数为："<<letter<<endl;
                cout<<"全文数字数为："<<num<<endl;
                cout<<"全文标点数为："<<quot<<endl;
                cout<<"全文空格数为："<<space<<endl;
                break;
            }
            case 8:{
                cout<<"请输入要查找的文本:"<<endl;
                string text;
                char s[100];
                getchar();
                gets(s);
                text = s;
                int line=1,offset=-1;
                editor.findTextInAll(text,&line,&offset);
                while(1){
                    if(offset==-1) break;
                    cout<<"文本在第"<<line<<"行的第"<<offset<<"个位置"<<endl;
                    editor.findTextInAll(text,&line,&offset);
                }
                break;
            }
            case 9:{
                cout<<"1.删除一段文本"<<endl;
                cout<<"2.删除特定位置的文本"<<endl;
                int as;
                cout<<"请输入选择：";
                cin>>as;
                if(as==1){
                    cout<<"请输入要删除的文字:"<<endl;
                    string text;
                    char s[100];
                    getchar();
                    gets(s);
                    text = s;
                    editor.deleteText(text);
                    cout<<"删除成功"<<endl;
                }else if (as ==2){
                    cout<<"输入行号：";
                    int line,pos,length;
                    cin>>line;
                    cout<<"\n输入位置：";
                    cin>>pos;
                    cout<<"\n输入长度：";
                    cin>>length;
                    editor.deleteText(line,pos,length);
                    cout<<"删除成功"<<endl;
                }
                
                break;
            }
            case 10:{
                editor.saveFile();
                cout<<"保存文本成功！"<<endl;
                break;
            }
            default:
                cout<<"输入数字错误"<<endl;
                continue;
        }
    }
}
int main()
{
    showInstructions();
    getChoice();
   // system("pause");
    return 0;
}



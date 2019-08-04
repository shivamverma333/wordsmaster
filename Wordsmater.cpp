#include<bits/stdc++.h>
using namespace std;
void file_handling();
vector <string> s1;
string p1,p2;
vector <char> l1{'e','a','o','n','r','l','d','i','h','y'};
vector <int> l2{1,2,3,4,5,1,3,4,5,5};
//Rules for game.
void rules()
{
    cout<<"\n";
    cout<<"\n";
    cout<<"\t\t\t\t\t\t RULES"<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"1.)The players are provided with a set of 5 random letters and each letter has points ranging from 1 to 5."<<"\n";
    cout<<"\n";
    cout<<"2.) A player has to make a word using the provided letters or if unable to do so they can pass their turn to the next player."<<"\n";
    cout<<"\n";
    cout<<"3.) The sum of points corresponding to each letter in a word entered by the player is his/her score after that turn."<<"\n";
    cout<<"\n";
    cout<<"4.) The game ends when both the players pass their turn."<<"\n";
    cout<<"\n";
    cout<<"5.) At the end of the game the player scoring the maximum points wins."<<"\n";
    cout<<"\n\n\n";
    cout<<" \tNOTE : All the words entered here should be meaningful.\n\tRepetition of the given letters is allowed !!"<<"\n";
    cout<<"\n\n\n";
    file_handling();
}

//taking words as input from a file and storing in vector
void file_handling()
{
    string s;

    ifstream file;
    file.open("words.txt");
    while(!file.eof())
    {
        file>>s;
        s1.push_back(s);
    }
}
void players()
{
        cout<<"\t\t\t:::\tWELCOME TO THE GAME 'KNOW THE WORDS'\t:::"<<"\n\n\n";
        cout<<"Player 1 enter your name"<<"\n";
        cin>>p1;
        cout<<"\n\n";
        cout<<"Player 2 enter your name"<<"\n";
        cin>>p2;
        cout<<"\n\n";
        cout<<"Let's see who know the words better "<<p1<<" or "<<p2<<"\n\n\n";
}
void display()
{
    cout<<"\n";
    cout<<"\n";
    cout<<"Use the given list of letters to make words"<<"\n";
    cout<<"\n";
    int i;
    cout<<"\t\tLetters"<<"\t";
    for(i=0;i<l1.size();i++)
    {
        cout<<l1[i]<<" ";
    }
    cout<<"\n";
    cout<<"\t\tPoints"<<"\t";
    for(i=0;i<l2.size();i++)
    {
        cout<<l2[i]<<" ";
    }
    cout<<"\n";
    cout<<"\n";

}
bool valid(string word)
{
    int i;
    for(i=0;i<s1.size();i++)
    {
        if(word.compare(s1[i])==0)
        {
            return true;
        }
    }
    return false;
}
struct node
{
    string data;
    struct node*left;
    struct node*right;
}*start=NULL,*nn;
struct node* create(string s)
{
    nn=(struct node*)malloc(sizeof(struct node));
    nn->left=NULL;
    nn->right=NULL;
    nn->data=s;
    return nn;
}
void insert(node* &root, string s)
{
	if (root == nullptr)
	{
		root = create(s);
		return;
	}
	if (s.compare(root->data)<0)
		insert(root->left, s);
	else
		insert(root->right, s);
}

bool search(struct node *root,string s)
{
   while (root != NULL)
    {
        if (s.compare(root->data)>0)
            root = root->right;
        else if (s.compare(root->data)<0)
            root = root->left;
        else
            return false;
    }
    return true;
}



int points(string word)
{
    int i,j,sum=0;
    for(i=0;i<word.length();i++)
    {
        for(j=0;j<l1.size();j++)
        {

            if(word[i]==l1[j])
            {
                sum+=l2[j];
            }
        }
    }
    return sum;
}
int main()
{
    rules();
    int score1=0,score2=0,sc1,sc2,turn=1;
    bool result=false,success;
    string word1,word2;
    char ch;
    cout<<"\nPress y to continue and any other key to exit.\n";
    cin>>ch;
    if(ch=='y')
    {
        players();
        display();
        do
        {
            if(turn%2!=0)
            {
                cout<<"\n"<<p1<<" please enter a word or press p to pass:"<<"\n";
                cin>>word1;
                if(word1=="p")
                {
                    turn++;
                    cout<<"\n";
                }
                else
                {
                    result=valid(word1);
                    if(result)
                    {
                        success=search(start,word1);
                        if(success)
                        {
                            insert(start,word1);
                           sc1=points(word1);
                           score1+=sc1;
                           cout<<"\nsuccess\n";
                           turn++;
                        }
                        else
                        {
                            cout<<"\nWord already Entered.\n";
                            turn++;
                        }
                    }
                    else
                    {
                        cout<<"\nInvalid Word\n";
                        turn++;
                    }

                }

            }
            else
            {
                cout<<"\n"<<p2<<" please enter a word or press p to pass:"<<"\n";
                cin>>word2;
                if(word2=="p")
                {
                    turn++;
                    cout<<"\n";
                }
                else
                {
                    result=valid(word2);
                    if(result)
                    {
                        success=search(start,word2);
                        if(success)
                        { insert(start,word2);
                           sc2=points(word2);
                           score2+=sc2;
                           cout<<"\nsuccess\n";
                           turn++;
                        }
                        else
                        {
                            cout<<"\nWord already Entered.\n";
                            turn++;
                        }
                    }
                    else
                    {
                        cout<<"\nInvalid Word\n";
                        turn++;
                    }

                }
            }

        }while(word1!="p"||word2!="p");
        cout<<p1<<"'s score = "<<score1<<"\n";
        cout<<p2<<"'s score = "<<score2<<"\n";
        if(score1>score2)
        {
            cout<<p1<<" knows more than "<<p2<<"\n\n";
        }
        else if(score2>score1)
        {
            cout<<p2<<" knows more than "<<p1<<"\n\n";
        }
        else
        {
            cout<<p1<<" and "<<p2<<" are equally intelligent"<<"\n\n\n";
        }
        cout<<"\n\n";
        cout<<"\t\t\tTHANKS FOR PLAYING"<<"\n";
    }
    else
    {
        exit(0);
    }
    return 0;
}




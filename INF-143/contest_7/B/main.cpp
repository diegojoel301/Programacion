#include<bits/stdc++.h>
 
using namespace std;

pair<string, int> f(string entrada)
{
    string a = "", b = "";
    bool flag = false;

    for(int i = 0; i < entrada.size(); i++)
    {
        if(entrada[i] == ' ')
            flag = true;
        else
        {
            if(not flag)
                a += entrada[i];
            else
                b += entrada[i];
        }
    }
    if(b == "")
        return make_pair(a, -1);
    return make_pair(a, stoi(b));
}

int main()
{ 
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
 
    string a, entrada;
    int b, value;
    pair<string, int> entradaPar;

    while(true)
    {
        getline(cin, entrada, '\n');

        entradaPar = f(entrada);

        a = entradaPar.first;
        b = entradaPar.second;
        
        if(a == "T")
            break;
        else if(a == "A")
        {
            if(pq.empty())
                cout << "Error\n";
            else  
                cout << pq.top() << "\n";
        }
        else if(a == "R")
        {
            if(pq.empty())
                cout << "Error\n";
            else
                pq.pop();
        }
        else
        { 
            if(a == "S")
                pq.push(b);
            else
            {
                if(a == "I")
                {
                    if(pq.empty())
                        cout << "Error\n";
                    else
                    {
                        value = pq.top() + b;
                        pq.pop();
                        pq.push(value);
                    }
                }
                if(a == "D")
                {
                    if(pq.empty())
                    {
                        cout << "Error\n";
                    }
                    else
                    {
                        value = pq.top() - b;
                        pq.pop();
                        pq.push(value);
                    }
                }
            }   
        }
    }
 
    return 0;
}
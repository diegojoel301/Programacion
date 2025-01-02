#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int L = -1;

	while(L != 0)
	{
		cin >> L;

		if(L == 0)
			break;

		string S = "+x";

		for(int i = 0; i < L - 1; i++)
		{
			string D;

			cin >> D;

			if( (D=="+y" || D=="-y" || D=="+z" || D=="-z") && S=="+x")
                    S = D;
            else
            {
                    if(D=="+y" && S=="+y")
                        S = "-x";
                    else if(D=="-y" && S=="+y")
                        S = "+x";

                    else if(D=="+z" && S=="+z")
                        S = "-x";
                    
                    else if(D=="-z" && S=="+z")
                        S = "+x";

                    else if(D=="+y" && S=="-x")
                        S = "-y";

                    else if(D=="-y" && S=="-x")
                        S = "+y";

                    else if(D=="+z" && S=="-x")
                        S = "-z";

                    else if(D==("-z") && S==("-x"))
                        S = "+z";

                    else if(D==("+y") && S==("-y"))
                        S = "+x";

                    else if(D==("-y") && S==("-y"))
                        S = "-x";

                    else if(D==("+z") && S==("-z"))
                        S = "+x";

                    else if(D==("-z") && S==("-z"))
                        S = "-x";
             }
        }
        cout << S << "\n";
	}
	return 0;
}


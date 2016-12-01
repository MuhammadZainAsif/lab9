#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;


void quadratic(float a, float b, float c){

float x1, x2, determinant, realPart, imaginaryPart;
    
    determinant = b*b - 4*a*c;
    
    if (determinant > 0) {
        x1 = (-b + sqrt(determinant)) / (2*a);
        x2 = (-b - sqrt(determinant)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    
    else if (determinant == 0) {
        cout << "Roots are real and same." << endl;
        x1 = (-b + sqrt(determinant)) / (2*a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-determinant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }


}



void cubicsolve(float a,float b,float c,float d)
{
    float root1Re,root2Im,root2Re,root3Im,root3Re;
    if (a == 0)
    {
        cout<<"The coefficient of the cube of x is 0. Please use the utility for a SECOND degree quadratic. No further action taken.";
        
    } //End if a == 0

    if (d == 0)
    {
        cout<<"One root is 0. Now divide through by x and use the utility for a SECOND degree quadratic to solve the resulting equation for the other two roots. No further action taken.";
       
    } //End if d == 0
    b /= a;
    c /= a;
    d /= a;
    float disc, q, r, dum1, s, t, term1, r13;
    q = (3.0*c - (b*b))/9.0;
    r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
    r /= 54.0;
    disc = q*q*q + r*r;
    float root1Im = 0; //The first root is always real.
	
    term1 = (b/3.0);
    if (disc > 0) { // one root real, two are complex
        s = r + sqrt(disc);
        s = ((s < 0) ? -pow(-s, (1.0/3.0)) : pow(s, (1.0/3.0)));
        t = r - sqrt(disc);
        t = ((t < 0) ? -pow(-t, (1.0/3.0)) : pow(t, (1.0/3.0)));
        root1Re = -term1 + s + t;
        term1 += (s + t)/2.0;
        root3Re = root2Re = -term1;
        term1 = sqrt(3.0)*(-t + s)/2;
        root2Im = term1;
        root3Im = -term1;
       
    } 
    // End if (disc > 0)
    // The remaining options are all real
    root3Im = root2Im = 0;
    if (disc == 0){ // All roots real, at least two are equal.
        r13 = ((r < 0) ? -pow(-r,(1.0/3.0)) : pow(r,(1.0/3.0)));
        root1Re = -term1 + 2.0*r13;
        root3Re = root2Re = -(r13 + term1);
       
    } // End if (disc == 0)
    // Only option left is that all roots are real and unequal (to get here, q < 0)
    q = -q;
    dum1 = q*q*q;
    dum1 = acos(r/sqrt(dum1));
    r13 = 2.0*sqrt(q);
    root1Re = -term1 + r13*cos(dum1/3.0);
    root2Re = -term1 + r13*cos((dum1 + 2.0*3.14159265358979323846)/3.0);
    root3Re = -term1 + r13*cos((dum1 + 4.0*3.14159265358979323846)/3.0);
    
	cout<<"Root 1 ="<<root1Re<<"+"<<root1Im<<endl;
	cout<<"Root 2 ="<<root2Re<<"+"<<root2Im<<endl;
	cout<<"Root 3 ="<<root3Re<<"+"<<root3Im<<endl;

}  //End of cubicSolve


bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}


bool validate(string s){
    
    stack<char>  St;
	for(int i =0;i<s.length();i++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
			St.push(s[i]);
		else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if(St.empty() || !ArePair(St.top(),s[i]))
				return false;
			else
				St.pop();
		}
	}
	unsigned int t = 0;

    if(s.size()<3)

    {

        cout<<"ERROR! Your equation needs at least 3 characters.";
          return false;
    }
      int count = 0;
    for(unsigned int i = 0; i<s.size(); i++)

    {

        // if(!isdigit(s.at(i))&&(s.at(i)!='+')&&(s.at(i)!='-')&&(s.at(i)!='/')&&(s.at(i)!='*')&&(s.at(i)!='.')){

        //     cout<<"ERROR! One of your characters is invalid.";
        //      return false;
        // }

        if((s.at(i)=='+')||(s.at(i)=='-')||(s.at(i)=='/')||(s.at(i)=='*'))

            t++;
        if(s.at(i)=='='){
            count++;
            }
        if(((s.at(i)=='/')&&(s.at(i+1)=='0')&&(s.at(i+2)!='.')))

        {

           cout<<"ERROR! You can't divide by 0.";
             return false;

        }

    }
    if(count==1){
        return true;
        }else{
            return false;
            }
    if(t<1)

    {

       cout<<"ERROR! No equation.";
         return false;

    }

	return St.empty() ? true:false;
    }

int main()
{
    string s;
    cout<<"enter alg equation";
  cin>>s;
  if(validate(s)){
      cout<<"Equation is true!";
      }else{
          cout<<"Equation is false!";
          }
    float a=0,b=0,c=0,d=0; 
	int eq=0;
  for(int i =0;i<s.length();i++)
	{
	    if(s[i]=='='){eq++;}
		cout<<s[i]<<endl;
	    if(s[i]=='^'&&eq==0&&s[i+1]=='3'){
	       if(isdigit(s[i-2]))
			   cout<<s[i-2];
		   char* aa = &s[i-2];
		   std::string fs(aa);
           float f=std::stof(fs);
		   if(s[i-3]=='-'){f=-f;}
	       a+=f;
	       
	    }
	    else if(s[i]=='^'&&eq==0&&s[i+1]=='2'){
	       if(isdigit(s[i-2]))
			    cout<<s[i-2];
	        char* bb = &s[i-2];
		   std::string fs(bb);
           float f=std::stof(fs);
		   if(s[i-3]=='-'){f=-f;}
	       b+=f;
	    }
	    else if(s[i]=='^'&&eq==0&&s[i+1]=='1'){
	       if(isdigit(s[i-2]))
			   cout<<s[i-2];
		   char* cc = &s[i-2];
		   std::string fs(cc);
           float f=std::stof(fs);
		   if(s[i-3]=='-'){f=-f;}
	       c+=f;
	       
	    }
	    else if(s[i]=='='){
			char* dd = &s[i+1];
		   std::string fs(dd);
           float f=std::stof(fs);
	       d=f;
	        }
        }
  cout<<"a ="<<a<<endl;
  cout<<"b ="<<b<<endl;
  cout<<"c ="<<c<<endl;
  cout<<"d ="<<c<<endl;
  if(a==0&&b==0){
  cout<<"Linear root ="<<d/c<<endl; 
  }
  else if(a==0)
  {
  quadratic(b,c,-d);
  }
  else if(a!=0){
  cubicsolve(a,b,c,-d);
  }
  system("pause");
}

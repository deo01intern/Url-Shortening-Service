#include<bits/stdc++.h>
using namespace std;

string ConvertToShortURL(long long int n)
{
   string mylist="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   
   string shortUrl="";
   
   while(n)
   {
     shortUrl+=mylist[n%62];
	 n/=62;
   }
   
   
   reverse(shortUrl.begin(),shortUrl.end());
   
   return shortUrl;
}

int  FindIdFromShortURL(string ShortUrl)
{
    long long int n=0;
	
	// extract string present after "/" eg. http://tinyurl/abcdef
	// calculate index to map and find corresponding long url from database
	
	for(int i=0;i<ShortUrl.size();i++)
	{
	    if(ShortUrl[i]>='a' && ShortUrl[i]<='z')
		n=n*62+ShortUrl[i]-'a';
		else if(ShortUrl[i]>='A' && ShortUrl[i]<='Z')
		n=n*62+ShortUrl[i]-'A'+26;
		else if(ShortUrl[i]>='0' && ShortUrl[i]<='9')
		n=n*62+ShortUrl[i]-'0'+52;
	
	}
	
	// write sql query to fetch long url mapped against index (n) and return it.
	
	
	return n;

}

int main()
{
   
   
   string longURL, shortURL="http://tinyurl/";
   
   long long int n=12345;
   
   cout<<"Please provide your url"<<endl;
   cin>>longURL;
   
   
   
  // save this longURL in database and fetch incremented index value and pass it to ConvertToShortURL function 
  // let it be n=12345
  
  string temp= ConvertToShortURL(n);
  shortURL+=temp;
  
  cout<<"Calculated short url is :"<< shortURL<<endl;
    
}

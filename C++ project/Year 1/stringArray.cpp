#include<bits/stdc++.h>
using namespace std;
char itc(int k){
	if (k==0){
		return '0';
	}
	if (k==1){
		return '1';
	}
	if (k==2){
		return '2';
	}
	if (k==3){
		return '3';
	}
	if (k==4){
		return '4';
	}
	if (k==5){
		return '5';
	}
	if (k==6){
		return '6';
	}
	if (k==7){
		return '7';
	}
	if (k==8){
		return '8';
	}
	if (k==9){
		return '9';
	}
}

int chquest(char*s){
	
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='?'){
			return 0;
		}
	}
	return 1;
}

void rtn(char*s,int k){
	int i=0,n=k,c,f,stat=0;
	//cout<<strlen(s);
	for (i=strlen(s)-1;i>=0;i--){
		c=n%10;
		//if ((s[i])!=itc(c)){
		//	break;
		//}
		//cout<<s[i]<<' '<<itc(c)<<endl;
		if (s[i]=='?'){
			f=c;
			//return c;
		} else{
			if (s[i]!=itc(c)){
				stat=1;
				break;
			}
		}
		n=n/10;
	}
	if (stat==0){
		cout<<f<<' ';
	}
}

void strarr(char a[], char b[], char c[]){
	//int*a;
	//a=(int*)malloc(1000*sizeof(int));
	int stat=0;
    int x,y,z,d=0;
    char*f=strtok_r(a," ",&a);
    char*g=strtok_r(b," ",&b);
    char*h=strtok_r(c," ",&c);
    while ((f!=NULL)){
    	//cout<<f<<' '<<g<<' '<<h<<endl;
    	//cout<<atoi(f)<<' ';
        if (!chquest(f)){
        	y=atoi(g);
            z=atoi(h);
            x=z-y;
            //cout<<x<<endl;
            //cout<<f;
            rtn(f,x);
        }
        
        if (!chquest(g)){
        	x=atoi(f);
            z=atoi(h);
            y=z-x;
            //cout<<x<<endl;
            //cout<<f;
            rtn(g,y);
        }
        
        if (!chquest(h)){
        	x=atoi(f);
            y=atoi(g);
            z=x+y;
            //cout<<x<<endl;
            //cout<<f;
            rtn(h,z);
        }
 
        //cout<<a[d]<<' ';
        f=strtok_r(NULL," ",&a);
        g=strtok_r(NULL," ",&b);
        h=strtok_r(NULL," ",&c);
    }
    //a[d+1]=d;
    //cout<<'|'<<n<<endl;
    //return a;
}
int main(){
    char a[1000],b[1000],c[1000];
    fgets(a,1000,stdin);
    fgets(b,1000,stdin);
    fgets(c,1000,stdin);
    int m=0,n=0,p=0,i=0,j;
    a[strlen(a)-1]='\0';
    b[strlen(b)-1]='\0';
    c[strlen(c)-1]='\0';
    /*int*x=strarr(a);
    int*y=strarr(b);
    int*z=strarr(c);
    //cout<<atoi("2?");
    while (x[i]){
    	if (x[i]==-1){
    		cout<<z[i]-y[i]<<' ';
		}
		if (y[i]==-1){
			cout<<z[i]-x[i]<<' ';
		}
		if (z[i]==-1){
			cout<<x[i]+y[i]<<' ';
		}
    	i++;
	}*/
	//cout<<a<<endl;
	//cout<<'f';
	//cout<<b<<endl;
	//cout<<c<<endl;
	strarr(a,b,c);
}

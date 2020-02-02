void moment(){
	
	const int M = 9;//9;
	const int a = 4;
	const int c=1;
	const int n = 10000000;
	int x;
	float xkk;

	x = 3;
	
	for(int i=0;i<=10;i++){

			
           x = (a*x + c) % M;  
           cout<<x<<endl;
			xkk += pow(x,5);
			
	}	


	cout<<"The 5th moment of this distribution is "<<xkk/10<<endl;

}
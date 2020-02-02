void MCintegration(){
	
	float n_under = 0.;
	float n_total = 100.;
	float value = 0.;
	float x,y;
	float x_high = 1.;
	float x_low = 0.;
	float y_high = 1.;
	float y_low = 0.;
	float f = 0.;

	for(int i=1;i<=n_total;i++){

		x =  gRandom->Rndm();
		y =  gRandom->Rndm();
		f += x*y/n_total;

		if (y<=1/x){
			n_under+=1;
			// cout<<n_under;
		}
		value = n_under/n_total;
		
	}
	cout<<value<<endl;
	cout<<"f "<<f<<endl;
}	
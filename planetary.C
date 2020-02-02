void planetary(float e=0.206){
	
 	     const int n=2000;
 	     float dt=0.001;
 	     float pi = 3.1415;
 	     float Vx[n],Vy[n],x[n],y[n],r[n];


 	     float a;
 	     a=1;
 	     float b;
 	     b=a*sqrt(1-(e*e));
 	     x[0]=a*(1+e);//1;//0.47;//a*(1+e);	//in AU
 	     y[0]=0;
 	     Vx[0]=0;	//in AU/yr
 	     Vy[0]=5;//2*pi;//8.2;//2*pi;



 	for(int i=0;i<n-1;i++){

 		r[i] = sqrt(x[i]*x[i] + y[i]*y[i]);

 		// Vx[i+1] = Vx[i] - ((4*pi*pi* x[i])/(r[i]*r[i]*r[i]))*dt;

 		Vx[i+1] = Vx[i] - ((4*pi*pi* x[i])/(pow(r[i],3.0)))*dt;

 		Vy[i+1] = Vy[i] - ((4*pi*pi*y[i])/(pow(r[i],3.0)))*dt;

 		// Vy[i+1] = Vy[i] - ((4*pi*pi* y[i])/(r[i]*r[i]*r[i]))*dt;

 		x[i+1] = x[i] + Vx[i+1]*dt;

 		y[i+1] = y[i] + Vy[i+1]*dt;


 	}

 	gr1 = new TGraph(n-1,x,y);
	gr1->SetTitle("Simulation of elliptical orbit");
	gr1->GetXaxis()->SetTitle("x, [AU]");
	gr1->GetYaxis()->SetTitle("y, [AU]");
	gr1->SetLineColor(kRed);
	// gr1->SetMarkerStyle(20);
	gr1->Draw();


}
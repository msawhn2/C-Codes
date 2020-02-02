void stringspectrum(){
	
		const int nmax = 1000;
		const int M=100;
	float dx = 0.01;
	float c = 300;
	float dt = dx/c;
	float r2;
	float y[3][M];
	// float x[M];
	// const int time = 1000;
	// float t[time];
	const int N = 3000;
 
  float pi = 3.1415926;

  float t[nmax],Y[nmax],w[nmax],x[M];//,a0,theta1[n];
  float f[N],a[N],b[N],p[N];



	canvas = new TCanvas("canvas","wave",0,0,800,700);
	canvas->Draw();


	for(int i=0;i<M;i++){
		y[1][i] =0;
		y[0][i] =0;
		y[2][i] =0;

		x[i] = i*dx;

	// }


	// for(int i=0; i<nmax-1;i++){
  
  if((i!=0) && (i!=M-1)){
		
		y[1][i] = exp(-1000*(x[i] - 0.3)*(x[i] - 0.3));
		y[0][i] = exp(-1000*(x[i] - 0.3)*(x[i] - 0.3));
	}
}

		// y[0][0] = 0;
		// y[1][0] = 0;
		// y[0][nmax-1] = 0;
		// y[1][nmax-1] = 0;

		
	r2 = (dt*c/dx)*(dt*c/dx);

		for(int j=0;j<nmax;j++){

				for(int i=1;i<M-1;i++){

	y[2][i] = 2* (1-(r2*r2)) * y[1][i] - y[0][i] + (r2*r2) * (y[1][i+1] + y[1][i-1]);

		Y[j] = y[1][5];
		t[j] = j*dt;
	}

		for(int i=1;i<M-1;i++){


			y[0][i] = y[1][i];
			y[1][i] = y[2][i];

			// cout<<y[1][i];		

		
	}

	}


	f[1] = 1.0;

	for(int j=0;j<N;j++){

  		a[j]=b[j]=0;
  		f[j]=f[1]*j;

  		for(int i=1;i<nmax-1;i++){

  		a[j] = a[j] + cos(2*pi*f[j]*t[i])*Y[i];
  		b[j] = b[j] + sin(2*pi*f[j]*t[i])*Y[i];
//cout<<a[j]<<endl;
}


      a[j] = 2*(cos(2*pi*f[j]*t[0])*Y[0]*0.5*dt + a[j]*dt + cos(2*pi*f[j]*t[nmax-1])*Y[nmax-1]*0.5*dt);
  	  b[j] = 2*(sin(2*pi*f[j]*t[0])*Y[0]*0.5*dt + b[j]*dt + sin(2*pi*f[j]*t[nmax-1])*Y[nmax-1]*0.5*dt);
  	  p[j] = a[j]*a[j] + b[j]*b[j];


}
// for(int i=0; i<nmax; i++)
// {
// Y[i] = (a[0]/2);
//  for(int j=1; j<N; j++)
//   {
//     Y[i] += ((a[j]*cos(2*pi*f[j]*t[i])) + (b[j]*sin(2*pi*f[j]*t[i])));
//   }
// //  cout<<theta1[i]<<endl;

// }

   result2 = new TGraph (N,f,p);
   result2->SetTitle("Power Spectrum");
   result2->GetXaxis()->SetTitle("frequency");
   result2->GetYaxis()->SetTitle("Power");
   // result2->SetMaximum(1.0);
   // gr->SetMinimum(-1.0);
   result2->SetLineColor(kRed);
    result2->Draw("AL");


	canvas2 = new TCanvas("canvas2","wave",0,0,800,700);
	canvas2->Draw();
   result3 = new TGraph (nmax,t,Y);
   result3->SetTitle("frrequency Spectrum");
   result3->GetXaxis()->SetTitle("Time[s]");
   result3->GetYaxis()->SetTitle("Signal[arbitary units]");
   result3->SetLineColor(kRed);
    result3->Draw("AL");



}
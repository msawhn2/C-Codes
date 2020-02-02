void squarewave(){

	 const int N = 10;
  const int n = 1000;

  float dt = 1.0/(n-1);

  float pi = 3.1415926;

  float t[n],y[n],w[n],F[n],a0;
  float f[N],a[N],b[N],p[N];

  float Integral=0;
int move;
move=1;

  test = new TF1("test","3*sin(3*2*pi*x)+cos(5*2*pi*x)",0.0,1.0);

  for(int i=0;i<(n/2)-1;i++){

  	t[i] =i*dt;
  	y[i]=1*move;

  }

  for(int i=(n/2)-1;i<n-1;i++){

    t[i]=i*dt;
  	y[i]=-1.0*move;
  }
   f[1]=1;


  for(int j=0;j<N;j++){

  		a[j]=b[j]=0;
  		f[j]=f[1]*j;

  		for(int i=1;i<n-1;i++){

  		a[j] = a[j] + cos(2*pi*f[j]*t[i])*y[i];
  		b[j] = b[j] + sin(2*pi*f[j]*t[i])*y[i];
//cout<<a[j]<<endl;
}


      a[j] = 2*(cos(2*pi*f[j]*t[0])*y[0]*0.5*dt + a[j]*dt + cos(2*pi*f[j]*t[n-1])*y[n-1]*0.5*dt);
  	  b[j] = 2*(sin(2*pi*f[j]*t[0])*y[0]*0.5*dt + b[j]*dt + sin(2*pi*f[j]*t[n-1])*y[n-1]*0.5*dt);
  	  p[j] = a[j]*a[j] + b[j]*b[j];


}
  

	 cc = new TCanvas("c", "fourier", 0,0,1000,350);
    cc->Divide(3);

    cc->cd(1);
    test->SetTitle("Function with Fourier Series Approximation");
	test->GetXaxis()->SetTitle("Time [s]");
	test->GetYaxis()->SetTitle("y(t)");
	test->Draw();

	cc->cd(2);
   gr2 = new TGraph(N, f, a);
	gr2->SetMarkerStyle(21);
	gr2->SetMarkerColor(kBlue);
	gr3 = new TGraph(N, f, b);
	gr3->SetMarkerStyle(21);
	gr3->SetMarkerColor(kRed);
	gr3->SetTitle("Coefficients");
	gr3->GetXaxis()->SetTitle("Frequency");
	gr3->GetYaxis()->SetTitle("Coefficient Values");
	gr3->Draw("AP");
	gr2->Draw("sameP");
	
	cc->cd(3);

   result2 = new TGraph (N,f,p);
   result2->SetTitle("Power Spectrum");
   result2->GetXaxis()->SetTitle("frequency");
   result2->GetYaxis()->SetTitle("Power");
   result2->SetLineColor(kRed);
    result2->Draw("Al*");
	
}

   	






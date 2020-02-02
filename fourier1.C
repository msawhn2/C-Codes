
void fourier1(){


const int N = 10;
  const int n = 1000;

  float dt = 1.0/(n-1);

  float pi = 3.1415926;

  float t[n],y[n],w[n],F[n],a0,theta1[n];
  float f[N],a[N],b[N],p[N];

float length= 9.8; 
float g=9.8; 
float q=0.5; 
float Omega_D = 2.0/3;
float F_Drive=0.95;
float pi=3.14159;

const int n = 100; 
float t[n],theta[n],omega[n],theta1[n];

float w[n],F[n],a0;// not needed?

omega[0] = 0;  theta[0]=0.2;
float dt = 0.04;

const int N = 20;
float f[N],a[N],b[N],p[N];


 t[0] = 0;
 theta[0] = sin(2*pi*t[0]);
  float Integral=0;


  test = new TF1("test","2*sin(2*pi*x)",0.0,1.0);

  for(int i=0;i<n;i++){

  	t[i] =i*dt;
  	
    // omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(t[i]*Omega_D)*dt;
  y[i] = sin(2*pi*t[i]);
  // y[i] = test->Eval(theta[i+1]);

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
for(int i=0; i<n; i++)
{
theta1[i] = (a[0]/2);
 for(int j=1; j<N; j++)
  {
    theta1[i] += ((a[j]*cos(2*pi*f[j]*t[i])) + (b[j]*sin(2*pi*f[j]*t[i])));
  }
//  cout<<theta1[i]<<endl;

}


	 c = new TCanvas("c", "fourier", 0,0,1000,350);
    c->Divide(3);

    c_1->cd();
    test->SetTitle("Function with Fourier Series Approximation");
	test->GetXaxis()->SetTitle("Time [s]");
	test->GetYaxis()->SetTitle("y(t)");
	test->Draw();
	graph2 = new TGraph(n,t,theta1);
   graph2->SetLineColor(kBlue);
   graph2->Draw("sameL");
    leg2 = new TLegend(0.2,0.4,0.6,0.2);
	leg2->AddEntry(test,"function","l");
	leg2->AddEntry(graph2,"fourier transform","l");
	leg2->Draw("same");
  

	c_2->cd();
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
	 leg1 = new TLegend(0.2,0.4,0.6,0.2);
	leg1->AddEntry(gr2,"an","p");
	leg1->AddEntry(gr3,"bn","p");
	leg1->Draw("same");
	
	c_3->cd();
   result2 = new TGraph (N,f,p);
   result2->SetTitle("Power Spectrum");
   result2->GetXaxis()->SetTitle("frequency");
   result2->GetYaxis()->SetTitle("Power");
   result2->SetLineColor(kRed);
    result2->Draw("A*");
	
}
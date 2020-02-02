void fourierpendulum(){



float length= 9.8; 
float g=9.8; 
float q=0.5; 
float Omega_D = 2.0/3;
float F_Drive=0.95;
float pi=3.1415;

const int n = 500; 
float t[n],theta[n],omega[n],theta1[n];

float w[n],F[n],a0;// not needed?

omega[0] = 0;  theta[0]=0.2;
float dt = 0.04;

const int N = 50;
float f[N],a[N],b[N],p[N];


 	t[0] = 0;
 // theta[i+1] = sin(2*pi t[]);
for(int i=0;i<n-1;i++){
		
  t[i+1] =t[i]+ dt;

  omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(t[i]*Omega_D)*dt;
  theta[i+1] =  theta[i]+omega[i+1]*dt; 
 
  if(theta[i+1]>pi) {theta[i+1]-=2*pi; }
  if (theta[i+1]<-1.0*pi) {theta[i+1]+=2*pi; }

}

c = new TCanvas("c", "fourier", 10,10,1100,350);
c->Divide(3);
c->cd(1);
gth = new TGraph(n,t, theta);
gth->SetTitle("theta(t)");
gth->GetXaxis()->SetTitle("time");
gth->GetYaxis()->SetTitle("theta");
gth ->Draw("AL");


f[1]=1./(dt*n);

 for(int j=0;j<N;j++){

	a[j]=b[j]=0;
  	f[j]=f[1]*j;

  	for(int i=0;i<n;i++){

  	a[j] = a[j] + cos(2*pi*f[j]*t[i])*theta[i]*dt;
  	b[j] = b[j] + sin(2*pi*f[j]*t[i])*theta[i]*dt;
//cout<<a[j]<<endl;
	}


//    a[j] = 2*(cos(2*pi*f[j]*t[0])*theta[0]*0.5*dt + (a[j]*dt) + cos(2*pi*f[j]*t[n-1])*theta[n-1]*0.5*dt);
  //  b[j] = 2*(sin(2*pi*f[j]*t[0])*theta[0]*0.5*dt + (b[j]*dt) + sin(2*pi*f[j]*t[n-1])*theta[n-1]*0.5*dt);
  
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
  graph2 = new TGraph(n,t,theta1);
   graph2->SetLineColor(kBlue);
   graph2->Draw("sameL");
    leg2 = new TLegend(0.2,0.4,0.6,0.2);
	leg2->AddEntry(gth,"function","l");
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
result2->Draw("AL");
	
}

   	
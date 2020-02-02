void decay(float dt = 0.05)
{

int N0=1000; float tau = 1.;
cout<<"Initial number of nuclei "<< N0<<endl;


//number of steps
const int n = 50;   //need to make n a constant for arrays


//Arrays with measurements and errors:
float    N[n+1], t[n+1];  

//N[0] and t[0] -- will store initial values:
t[0] = 0; N[0] = N0;

cout<<"ok"<<endl; flush(cout);

//Do calculations:

for(int i = 0; i < n; i++)	
{
	t[i+1] = t[i]+dt;
	
	if(N[i]==0) { N[i+1] =0; } 
	else	{ N[i+1] = N[i] - (N[i]/tau)*dt;}

     // if(N[i+1]<0)N[i+1]=0;
	cout<< "i=" << i << ", t =" <<t[i]<<", N="<<N[i]<<endl;

}

//Store results in a TGraph:
gr = new TGraph(n+1,t,N);
gr->SetTitle("Radioacative decay example");
gr->GetXaxis()->SetTitle("time, [s]");
gr->GetYaxis()->SetTitle("Abundance N [nuclei]");

//Plot results:

c = new TCanvas("c","Radioacative decay example",10,10,500,400);
c->SetLogy(1);  //set logarithmic scale for drawing
c->Draw();
gr->SetMarkerStyle(20);
gr->Draw("AP");


//Define function with exact solution
solution = new TF1("solution","[0]*exp(-x/[1])",0,t[n]);
solution->SetParameter(0,N0);
solution->SetParameter(1,tau);

solution->SetLineColor(2);
solution->Draw("same");


//Saving a plot

//Creating a ROOT file to store the histogram:
fOut  = new TFile("decay.root","RECREATE");
gr->Write();
solution->Write();

fOut->Close();


//Fancy stuff: creating a legend  ON the plot:

char str[80];
sprintf(str, "Numerical solution for dt=%.2f", dt);

leg = new TLegend(0.3,0.7,0.9,0.9);
leg->AddEntry("solution","Exact Solution","l");
leg->AddEntry("gr",str,"p");
leg->Draw("same");


char filename[80];
sprintf(filename, "decaydt%.2f.gif", dt);

c->SaveAs(filename);


}
void velocityeqn(float dt=0.2)
{
	 float V0=-30; 
	 float g=9.8;
cout<<"Initial velocity "<<V0<<endl;


//number of steps
const int n = 50;   //need to make n a constant for arrays
float V[n+1], t[n+1];  
t[0] = 0; V[0] = V0;

cout<<"ok"<<endl; flush(cout);


for(int i = 0; i < n; i++)	
{
	t[i+1] = t[i]+dt;
	V[i+1]=V[i]-(g*dt);
	cout<< "i=" << i << ", t =" <<t[i]<<", V="<<V[i]<<endl;

}
cout<<"The numerical solution is "<<V[i]<<" m/s"<<endl;

gr = new TGraph(n+1,t,V);
gr->SetTitle("Freefall velocity equation");
gr->GetXaxis()->SetTitle("time, [s]");
gr->GetYaxis()->SetTitle("Velocity V [m/s]");

//Plot results:

c = new TCanvas("c","Freefall velocity equation",10,10,500,400);
//c->SetLogy(1);  //set logarithmic scale for drawing
c->Draw();
gr->SetMarkerStyle(20);
gr->Draw("AP");

//exact solution
float t_high = fabs((V0*2)/g);
TF1*Exact = new TF1("Exact","[0]-[1]*x",0,t_high);
Exact->SetParameters(V0,g);
Exact->SetLineColor(2);
Exact->Draw("same");
leg = new TLegend(0.11,0.4,0.35,0.25);
leg->AddEntry("Exact","Exact Solution","l");
leg->AddEntry("gr","Numerical solution","p");
leg->Draw("same");
 


}
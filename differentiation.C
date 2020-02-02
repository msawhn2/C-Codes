void differentiation()
{ 
  float pi =3.14159261;
  const int n=10;
  float x[n],y[n],diff[n],diff2[n];
  float dx=0.01;
 

 float step = (2*pi)/(n-1);

 TF1*function = new TF1("function","cos(x)",0,2*pi);
 function->SetTitle("cos(x) and its derivative");
 function->GetXaxis()->SetTitle("x, [degrees]");
  function->GetYaxis()->SetTitle("y, [degrees]");
 function->Draw();
 
 TF1*derivative = new TF1("derivative","-1.0*sin(x)",0,2*pi);
 derivative->SetLineColor(kBlue);
 derivative->Draw("same");


//forward difference approximation
  for (int i=0;i<n;i++)
  {
    x[i]=i*step;
    y[i]=function->Eval(x[i]);
    diff[i]=(function->Eval(x[i]+dx)-function->Eval(x[i]))/(dx);
    
  }
//mid-point approximation
  for (int i=0;i<n;i++)
  {
    x[i]=i*step;
    y[i]=function->Eval(x[i]);
    diff2[i]=(function->Eval(x[i]+0.5*dx)-function->Eval(x[i]-0.5*dx))/(dx);
    
  }

  gr1=new TGraph (n,x,y);
  gr1->SetMarkerStyle(20);
  gr1->Draw("sameP");
  gr = new TGraph (n,x,diff);
  gr->SetMarkerStyle(20);
  gr->Draw("sameP");


  gr2 = new TGraph(n,x,diff2);
  gr2->SetMarkerStyle(21);
  gr2->Draw("sameP");

leg = new TLegend(0.2,0.4,0.6,0.2);
leg->AddEntry(function,"cos(X) function","l");
leg->AddEntry(derivative,"-sin(x) function","l");
leg->AddEntry(gr,"derivative using forward difference approximation","p");
leg->AddEntry(gr2,"derivative using mid-point approximation","p");
leg->Draw("same");
   



}
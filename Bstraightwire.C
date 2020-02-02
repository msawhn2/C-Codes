void Bstraightwire(){
	
const int n = 100;
	const int N = 6;
	const float pi = 3.14159265;
	int i, j, k, l;
	float L = 10;
	float B[N];
	float x[n];
	float z[N];

	float C = 1/(4*pi);
	float dx = (2.*L)/(n-1);
// float dx = 0.1;
	cout<<"dx: "<<dx<<endl<<endl;

	for (l = 0; l < N; l++){
		z[l] = l+1;
		B[l] = 0;

		for (i = 0; i < n; i++) {
			x[i] = -L + 0.5 * i * dx; 
			B[l] = B[l] + C * (z[l] / pow((x[i]*x[i])+(z[l]*z[l]), 3./2)) * dx;

		}
		cout<<"z["<<l<<"] = "<<z[l]<<endl;
		cout<<"B["<<l<<"] = "<<B[l]<<endl;
		cout<<endl;	
	}

	gr = new TGraph(N, z, B);
	gr->SetTitle("Magnetic Field due to a Wire; Distance From Wire (m); Magnetic Field (B)");
	gr->Draw("A*");

	exact = new TF1("exact sol mag field", "[0]*[1]/(2*[2]*x)", .1, N);
	exact->SetParameter(0, 1.); //mu_knot
	exact->SetParameter(1, 1.0); //CUrrent
	exact->SetParameter(2, pi);
	exact->SetLineColor(kBlue);
	exact->Draw("same");


	leg = new TLegend(0.2,0.3,0.5,0.2);
leg->AddEntry(gr,"Calculated Magnetic Field","p");
leg->AddEntry(exact,"exact solution","l");
leg->Draw("same");





	

}

	


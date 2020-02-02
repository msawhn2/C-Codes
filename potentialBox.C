void potentialBox() {

	const int n = 10;
	int i, j, k;
	float dx, dy, dz;
	float v[n][n];
	float vNew[n][n];
	float dv = 0; 
	dx = fabs(-1. - 1.)/(n-1);
	dy = fabs(-1. - 1.)/(n-1);

	
	//assigning boundary conditions
	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {

			v[j][i] = 0;
			vNew[j][i] = 0;

			if (j >= n-2 && i <= 1){
				v[j][i] = 1;
				vNew[j][i] = 1;
			}

		}
	}

	for (j = 0; j < n; j++){
		for (i = 0; i < n; i++) {
			cout<<v[j][i]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;

	for (k = 0; k < 500; k++) {
		dv = 0;
		for (j = 1; j < n; j++) {
			for (i = 0; i < n-1; i++) {

				if (j < n-2 && i > 1) { //calc values not on edges
					//vNew[j][i] = 2;
					vNew[j][i] = 1./4 * (v[j][i+1] + v[j][i-1] + v[j+1][i] + v[j-1][i]);
				}
				if (i <= 1 && j != 0 && j < n-2) { //calc values on left edge
					//vNew[j][i] = 3;
					vNew[j][i] = 1./3 * (v[j][i+1] + v[j+1][i] + v[j-1][i]);
				}
				if (j >= n-2 && i > 1 && i != n-1) { //calc values on bottom row
					//vNew[j][i] = 4;
					vNew[j][i] = 1./3 * (v[j][i+1] + v[j][i-1] + v[j-1][i]);
				}

				dv = dv + fabs(vNew[j][i] - v[j][i]);
				v[j][i] = vNew[j][i];

			}
		}
		if (dv <= 0.00001) { cout<<"break, k = "<<k<<endl; break; }
	}

	for (j = 0; j < n; j++){
		for (i = 0; i < n; i++) {
			printf("%.2f ", vNew[j][i]);
		}
		cout<<endl;
	}

	//duplicate first quadrant into fourth quadrant 
	float v2[2*n][2*n];
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			v2[i][j+n] = v[i][j];
		}
		for(j=0; j<n; ++j){
				v2[i][j] = v[i][n-j-1];
		}
	}

	//duplicate first and fourth quadrant into second and third
	for(i=0; i<n; ++i){
		for(j=0; j<2*n;++j){
			v2[i+n][j] = v2[n-i-1][j];
			//v2[i+n][j] = -1;
		}
	}

	//print full array with filled quadrants
	for (j = 0; j < 2*n; j++){
		for (i = 0; i < 2*n; i++) {
			printf("%.2f ", v2[j][i]);
		}
		cout<<endl;
	}



	//need to adjust this so that it shows in all four corners
	hist = new TH2D("hist", "potential field", 2*n, -1, 1, 2*n, -1, 1);
	hist->GetXaxis()->SetTitle("X");
	hist->GetYaxis()->SetTitle("Y");

	for (j = 0; j < 2*n; j++){
		for (i = 0; i < 2*n; i++){
			hist->SetBinContent(j+1, i+1, v2[j][i]);
		}
	}
	gStyle->SetOptStat(0);
	hist->Draw("surf");

c = new TCanvas("c", "squarebox", 0,0,1000,350);
c->Draw();

gStyle->SetOptStat(0);

	hist1 = new TH2D("hist1", "electric field", 2*n, -1, 1, 2*n, -1, 1);
	hist1->Draw("");
	for (j = 1; j < 2*n-1; j++) {
		for (i = 1; i < 2*n-1; i++) {

			Ex[j][i] = -1.0 * (v2[j][i+1] - v2[j][i-1])/(2*dx);
			Ey[j][i] = -1.0 * (v2[j+1][i] - v2[j-1][i])/(2*dy);

			if (Ex[j][i] == 0 && Ey[j][i] == 0){
				continue;
			}
			gr = new TArrow(-1 + j * dx, -1 + i * dy, -1 + j * dx + Ey[j][i]/10, -1 + i * dy + Ex[j][i]/10);
			gr->SetArrowSize(0.02);
			gr->Draw("same");
		}
	}

}
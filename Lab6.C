fourT() {
	
	const int N = 10; //number of terms to calculate
	const int n = 10000; //small bins for integration
	const float pi = 3.14159265;
	float dt; 

	float t[1][n]; //array for data points
	float y[3][n]; //array for data points

	float coef[2][N]; //array for results (a and b)
	float f[1][N]; //array for results
	float p[1][N]; //array for results
	float width;
	int i, j; //j relates to coeficients (n in power point sliedes)

	float width;
	float intg[2][n];
	float intgTot[2];

    float J[N];
    int flip;
	int count;

	dt = 1.0 / (n - 1); //time step
	count = 0;
	flip = 1;

	//Function to test code
	test = new TF1("test", "3 * sin(3 * 2 * pi * x) + cos(5 * 2 * pi * x)", 0., 1.0);

	for (int i = 0; i < n; i++) {
		//fill data arrays based on function want to calculate
		t[0][i] = i * dt;
		y[0][i] = test->Eval(t[0][i]);
		y[1][i] = 1*flip;

		count++;
		if (count == 2000) {
			flip = flip * -1;
			count = 0;
		}
	}

	f[0][1] = 1; //for t_max = 1 case

	//loop over all term orders
	for (j = 0; j < N; j++) {
		J[j] = j;
		f[0][j] = j[0][j] * j;
		coef[0][j] = coef[1][j] = 0;
		intgTot[0] = 0;
		intgTot[1] = 0;

		//integrate over all points for each term
		for (i = 1; i < n; i++) {
			//Trapezoidal implementation
			width = t[0][i] - t[0][i-1];
			intg[0][i] = cos(j * 2 * pi * t[0][i]) * ((y[1][i] + y[1][i-1]) * (width / 2)); //a
			intg[1][i] = sin(j * 2 * pi * t[0][i]) * ((y[1][i] + y[1][i-1]) * (width / 2)); //b
			intgTot[0] = intgTot[0] + intg[0][i];
			intgTot[1] = intgTot[1] + intg[1][i];
		}

		coef[0][j] = intgTot[0] * 2;
		coef[1][j] = intgTot[1] * 2;
		// cout<< "a["<<j<<"]: "<<coef[0][j]<<endl;		
		// cout<< "b["<<j<<"]: "<<coef[1][j]<<endl<<endl;
		// cout<<"J: "<<J[j]<<endl;
	}

	//reassemble function (set into y[2][])
	for (j = 0; j < n; j++) {
         y[2][j]=coef[0][0] / 2;
		for (i = 1; i < N; i++) {
			y[2][j] += (coef[0][i] * cos(i * 2 * pi *t[0][j]) + coef[1][i] * sin(i * 2 * pi * t[0][j]));
		}
	}
	

	//graphing
	c = new TCanvas("C", "weights", 0, 0, 1300, 800);
	c->Divide(3);
	c->cd(1);//reassembled fourier
	gr1 = new TGraph(n, t[0], y[2]);
     
	gr1->SetMarkerColor(kRed);
	gr1->Draw("AP");
	gr = new TGraph(n, t[0], y[1]);
	gr->SetTitle("Square wave");
     gr->GetXaxis()->SetTitle("Time");
	gr->GetYaxis()->SetTitle("Pulse");
	gr->SetMarkerColor(kBlue);
	gr->Draw("Lsame");
	c->cd(2);//weights an and bn
	graph = new TGraph(N, J, coef[0]);
	graph->SetTitle("A_n & B_n weights");
	graph->SetMarkerStyle(21);
	graph->SetMarkerColor(kBlue);
	graph->Draw("AP");
	graph1 = new TGraph(N, J, coef[1]);
	graph1->SetMarkerStyle(25);
	graph1->SetMarkerColor(kRed);
	graph1->Draw("AP");
	graph->Draw("sameP");
	c->cd(3);//power graph

}
	void CN1(){
	const int N = 20;
	const int Nt = 100;
	double T[N],a[N],b[N],c[N],d[N],h[N],p[N],x[N];
	const double K = 237.0;
	const double C = 900.0;
	const double R = 2700.0;
	const double L = 1.0;
	double dx = L/90;
	double dt = 2.0;
	double eta  = (K*dt)/(C*R*dx*dx);
	cout<<eta<<endl;	
	hplot = new TH2D("hplot", "Heat Diffusion Of an Al Rod",N,0,L,N,0,dt*N);
	cnvs = new TCanvas("cnvs", "Heat Diffusion of an Al Rod", 0 , 0, 900, 600);

	for(int j = 0; j < N; j++)// initialize all T(x,t) to 0
	{
		for(int i = 0; i < N; i++)
			{
				T[i] = 0;
			}
	} 

	for(int i = 0; i < N; i++)// initialize endpoints to 0
		{
			T[i] = 100.0;
		} 
		for(int i = 0; i < N; i++)// initialize temp of rod at t=0
			{
				T[0] = 0;
				T[N-1] = 0;
			} 
	for(int i = 0; i < N-1; i++) // set c
		{
			a[i] = 0;
			b[i] = -1.0;
			p[i] = -1.0;
			h[i] = -1.0;

			d[i] = 0;
			c[i] = 0;
		}
	for(int i = 0; i < N; i++)
		{
			d[i] = (2./eta) + 2.;
		}
	for(int i = 0; i < N-1; i++) // set c
		{
			c[i] = -1.0;
		}
	for(int i = 1; i < N; i++)
		{ // set a
			a[i] = -1.0;
		}
	for(int k = 0; k < Nt; k++)
		{
			for(int i = 0; i < N; i++)
				{
					hplot->SetBinContent(i+1,k,T[i]);
				}

			for(int i = 0; i < N - 2; i++)
				{
					b[i] = T[i] + (((2./eta)-2)*T[i+1]) + T[i+2]; 
				}

			h[0] = c[0]/d[0];
			p[0] = b[0]/d[0];

			for(int i = 1; i < N; i++)
				{
					h[i] = c[i]/(d[i] - (a[i] * h[i-1]));
					p[i] = (b[i] - (a[i]*p[i-1]))/(d[i] - (a[i]*h[i-1]));
				} 

			x[N - 1] = p[N - 1];
			for(int i = (N - 2) ; i >= 0; i--)
				{
					x[i] = p[i]- (h[i]*x[i+1]);

				}
			for(int i = 0; i < N-1; i++)
				{
					T[i+1] = x[i];
					cout<<x[i]<<endl;
				}
		}

	hplot->GetXaxis()->SetTitle("x[m]");
	hplot->GetXaxis()->SetTitle("t[s]");
	hplot->GetXaxis()->SetTitle("T[Degrees Celsius]");
	gStyle->SetOptStat(0);
	hplot->Draw("surf2");
}
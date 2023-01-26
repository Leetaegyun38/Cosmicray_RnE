void SingleTreeinput()
{
	TFile *f = TFile::Open("teeeeest.txt", "recreate");
	
	TTree *tree_test new TTree("test", "난 행복해");
	
	Double_t t_tree;
	
	tree_test->Branch("t_tree", &t_tree, "t_tree/D");
	
	for(int i=0;i<1e4;i++){
		
	tree_em->Fill();	 
	}
	f->cd();
	tree_em->Write();
	f->close();
}

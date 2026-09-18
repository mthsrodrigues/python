#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>

int main() {
    const int N = 1000;
    const double mean = 0.0;
    const double sigma = 1.0;

    TFile file("data_cpp.root", "RECREATE");
    TTree tree("tree", "Gaussian random numbers");

    double x;
    tree.Branch("x", &x, "x/D");

    TRandom3 rnd(0);

    for (int i = 0; i < N; ++i) {
        x = rnd.Gaus(mean, sigma);
        tree.Fill();
    }

    file.cd();
    tree.Write();
    file.Close();

    return 0;
}

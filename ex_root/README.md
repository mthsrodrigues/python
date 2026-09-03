# ROOT Exercise

## Data generation

The `generate.C` script generates 1000 random numbers from a Gaussian distribution with mean 0 and standard deviation 1. The values are stored in a TTree inside `dados.root`.

Run with:

    root -l -b -q generate.C

## Histogram and fit

The `plot.C` script reads the values from `dados.root`, fills a histogram and performs a Gaussian fit.

Run with:

    root -l -b -q plot.C

The fit results were:

- Mean: -0.00250
- Standard deviation: 0.96382

These values are close to the parameters used to generate the data, with mean 0 and standard deviation 1.

The resulting histogram is saved as `histograma.png`.
#
# run all unit tests (using 'testthat')
#
library(testthat)
library(bigWig2)

# pre-load test data
fpath = system.file("extdata", "test_probe_bp.bigWig", package="bigWig")
bwTest = load.bigWig(fpath)

test_package("bigWig2")

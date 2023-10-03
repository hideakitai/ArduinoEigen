# ArduinoEigen

Eigen (a C++ template library for linear algebra) for Arduino

## Eigen Version

- Eigen v3.4.0

## Usage

By using this library, Eigen can be used directly with Arduino. Please refer following official documents for the details of Eigen.

- [Getting Started](https://eigen.tuxfamily.org/dox/GettingStarted.html)
- [Quick reference guide](https://eigen.tuxfamily.org/dox/group__QuickRefPage.html)
- [Sparse matrix manipulations](https://eigen.tuxfamily.org/dox/group__TutorialSparse.html)

### A simple first program

```C++
#include <ArduinoEigen.h>

using Eigen::MatrixXd;

void setup() {
    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
}
```

### Matrices and vectors (dynamic)

```C++
#include <ArduinoEigenDense.h>

using namespace Eigen;

void setup() {
    MatrixXd m = MatrixXd::Random(3, 3);
    m = (m + MatrixXd::Constant(3, 3, 1.2)) * 50;

    VectorXd v(3);
    v << 1, 2, 3;

    VectorXd vo = m * v;
}
```

### Matrices and vectors (static)

```C++
#include <ArduinoEigenDense.h>

using namespace Eigen;

void setup() {
    Matrix3d m = Matrix3d::Random();
    m = (m + Matrix3d::Constant(1.2)) * 50;

    Vector3d v(1, 2, 3);
    Vector3d vo = m * v;
}
```

## Additional Features

### Pseudo Inverse by SVD decomposition

```C++
MatrixXd Jacobi {3, 4};
MatrixXd Jacobi_pinv {4, 3};

Jacobi <<
    1, 2, 3, 4,
    5, 6, 7, 8,
    9, 10, 11, 12;

Jacobi_pinv = Eigen::pseudoInverse(Jacobi);
```

## Note

This library does NOT support following boards because they don't have standard libraries.

- AVR (Uno, Nano, Mega, etc.)
- MEGAAVR (Uno WiFi, Nano Every, etc.)
- SAM (Due)

For such boards, consider using [EigenArduino](https://github.com/vancegroup/EigenArduino).

## Dependent Libraries

- [ArxTypeTraits](https://github.com/hideakitai/ArxTypeTraits)

## License

MPL-2.0

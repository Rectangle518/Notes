
export void ispc_sinx(
    uniform int N,
    uniform int terms,
    uniform float *x,
    uniform float *result
)
{
    for (uniform int i = 0; i < N; i += programCount)
    {
        int idx = i + programIndex;
        float value = x[idx];
        float numer = x[idx] * x[idx] * x[idx];
        uniform int denom = 6;
        uniform int sign = -1;

        for (uniform int j = 1; j <= terms; j++)
        {
            value += sign * numer / denom;
            numer *= x[idx] * x[idx];
            denom *= (2*j+2) * (2*j+3);
            sign *= -1;
        }
        result[idx] = value;
    }
}

export void ispc_sinx_foreach(
    uniform int N,
    uniform int terms,
    uniform float *x,
    uniform float *result
)
{
    foreach (i = 0 ... N)
    {
        float value = x[i];
        float numer = x[i] * x[i] * x[i];
        uniform int denom = 6;
        uniform int sign = -1;

        for (uniform int j = 1; j <= terms; j++)
        {
            value += sign * numer / denom;
            numer *= x[i] * x[i];
            denom *= (2*j+2) * (2*j+3);
            sign *= -1;
        }
        result[i] = value;
    }
}
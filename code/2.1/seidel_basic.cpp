
const int N;

float *A;

float TOLERANCE = 0.0001;

float fabs(float x)
{
    return x > 0 ? x : -x;
}

void solve(float *A)
{

    float diff, prev;
    bool done = false;

    while (!done) {
        diff = 0.f;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                prev = A[i * N + j];
                A[i * N + j] = (A[(i + 1) * N + j] + A[(i - 1) * N + j] + A[i * N + j + 1] + A[i * N + j - 1] + A[i * N + j]) * 0.2f;
                diff += fabs(prev - A[i * N + j]);
            }
        }
        if (diff / (N * N) < TOLERANCE) {
            done = true;
        }
    }
}
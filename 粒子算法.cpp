#include <iostream>
#include <vector>
#include <cmath>
#include <random>
using namespace std; 
// ����Ŀ�꺯�������⺯����
double objectiveFunction(double x) {
    return x * x; // ʾ��Ŀ�꺯��Ϊ x^2
}

// �������ӽṹ��
struct Particle {
    double position;
    double velocity;
    double bestPosition;
    double bestValue;
};

// PSO�㷨����
const int numParticles = 50;
const int maxIterations = 100;
const double inertiaWeight = 0.7;
const double cognitiveWeight = 1.5;
const double socialWeight = 1.5;

int main() {
    std::vector<Particle> particles(numParticles);

    // ��ʼ������Ⱥ
  	default_random_engine generator;
    uniform_real_distribution<double> distribution(-10.0, 10.0);

    for (int i = 0; i < numParticles; ++i) {
        particles[i].position = distribution(generator);
        particles[i].velocity = distribution(generator);
        particles[i].bestPosition = particles[i].position;
        particles[i].bestValue = objectiveFunction(particles[i].position);
    }

    double globalBestPosition;
    double globalBestValue = std::numeric_limits<double>::max();

    // PSO����
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        for (int i = 0; i < numParticles; ++i) {
            double newVelocity = inertiaWeight * particles[i].velocity +
                                 cognitiveWeight * distribution(generator) * (particles[i].bestPosition - particles[i].position) +
                                 socialWeight * distribution(generator) * (globalBestPosition - particles[i].position);

            particles[i].velocity = newVelocity;
            particles[i].position += particles[i].velocity;

            double newValue = objectiveFunction(particles[i].position);
            if (newValue < particles[i].bestValue) {
                particles[i].bestPosition = particles[i].position;
                particles[i].bestValue = newValue;
            }

            if (newValue < globalBestValue) {
                globalBestPosition = particles[i].position;
                globalBestValue = newValue;
            }
        }

        cout << "Iteration " << iteration + 1 << ": Global Best Value = " << globalBestValue << std::endl;
    }

    cout << "Optimal solution found at x = " << globalBestPosition << ", f(x) = " << globalBestValue << std::endl;

    return 0;
}

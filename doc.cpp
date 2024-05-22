#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Doctor {
public:
    string name;
    string specialty;
    double fees;

    Doctor(const string& _name, const string& _specialty, double _fees)
        : name(_name), specialty(_specialty), fees(_fees) {}
};

class Patient {
public:
    string name;
    int age;
    string problem;

    Patient(const string& _name, int _age, const string& _problem)
        : name(_name), age(_age), problem(_problem) {}
};

class Appointment {
public:
    string patientName;
    string doctorName;
    string date;
    string location;
    string status;

    Appointment(const string& _patientName, const string& _doctorName, const string& _date, const string& _location)
        : patientName(_patientName), doctorName(_doctorName), date(_date), location(_location), status("Pending") {}
};

class AppointmentSystem {
private:
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;

public:
    void addDoctor(const string& name, const string& specialty, double fees) {
        doctors.push_back(Doctor(name, specialty, fees));
        cout << "Doctor added successfully.\n";
    }

    void addPatient(const string& name, int age, const string& problem) {
        patients.push_back(Patient(name, age, problem));
        cout << "Patient added successfully.\n";
    }

    void addAppointment(const string& patientName, const string& doctorName, const string& date, const string& location) {
        bool patientFound = false;
        bool doctorFound = false;

        for (const Patient& patient : patients) {
            if (patient.name == patientName) {
                patientFound = true;
                break;
            }
        }

        for (const Doctor& doctor : doctors) {
            if (doctor.name == doctorName) {
                doctorFound = true;
                break;
            }
        }

        if (patientFound && doctorFound) {
            appointments.push_back(Appointment(patientName, doctorName, date, location));
            cout << "Appointment added successfully.\n";
        } else {
            cout << "Patient or Doctor not registered. Please add them first.\n";
        }
    }

    void viewAppointments() {
        if (appointments.empty()) {
            cout << "No appointments available.\n";
        } else {
            cout << "------------------------------------------------------------------------------------------------------------------\n";
            cout << "|  Sl.No  |  Patient Name  |  Doctor Name  |  Date        |  Location          |  Status       |\n";
            cout << "------------------------------------------------------------------------------------------------------------------\n";

            int slNo = 1;
            int row = 1;
            int col = 1;

            for (const Appointment& appointment : appointments) {
                cout << "  |  " << setw(6) << slNo << " | " << setw(13) << appointment.patientName << "  |  " << setw(12) << appointment.doctorName
                     << "  |  " << setw(10) << appointment.date << "  |  " << setw(18) << appointment.location
                     << "  |  " << setw(12) << appointment.status << "  |\n";

                slNo++;
                col++;

                if (col > 4) {
                    col = 1;
                    row++;
                }
            }
            cout << "------------------------------------------------------------------------------------------------------------------\n";
        }
    }
};

int main() {
    AppointmentSystem appointmentSystem;

    int choice;
    string doctorName, doctorSpecialty, patientName, patientProblem, date, location;
    double doctorFees;
    int patientAge;

    while (true) {
        cout << "Doctor Appointment System\n";
        cout << "1. Add Doctor\n";
        cout << "2. Add Patient\n";
        cout << "3. Add Appointment\n";
        cout << "4. View Appointments\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter doctor's name: ";
                cin >> doctorName;
                cout << "Enter doctor's specialty: ";
                cin >> doctorSpecialty;
                cout << "Enter doctor's fees: ";
                cin >> doctorFees;
                appointmentSystem.addDoctor(doctorName, doctorSpecialty, doctorFees);
                break;
            case 2:
                cout << "Enter patient's name: ";
                cin >> patientName;
                cout << "Enter patient's age: ";
                cin >> patientAge;
                cout << "Enter patient's problem: ";
                cin >> patientProblem;
                appointmentSystem.addPatient(patientName, patientAge, patientProblem);
                break;
            case 3:
                cout << "Enter patient's name: ";
                cin >> patientName;
                cout << "Enter doctor's name: ";
                cin >> doctorName;
                cout << "Enter appointment date (YYYY-MM-DD): ";
                cin >> date;
                cout << "Enter appointment location: ";
                cin >> location;
                appointmentSystem.addAppointment(patientName, doctorName, date, location);
                break;
            case 4:
                appointmentSystem.viewAppointments();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
return 0;
}

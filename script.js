let patients = [];

const diseases = {
    1: "Heart Attack",
    2: "Severe Wound/Bleeding",
    3: "Cancer",
    4: "Chest Pain",
    5: "Fracture",
    6: "Diabetes Checkup",
    7: "Infection",
    8: "Viral Fever",
    9: "Common Cold/Headache"
};

function addPatient() {
    let name = document.getElementById("name").value;
    let age = document.getElementById("age").value;
    let address = document.getElementById("address").value;
    let phone = document.getElementById("phone").value;
    let bloodgroup = document.getElementById("bloodgroup").value;
    let reg = document.getElementById("reg").value;
    let priority = document.getElementById("priority").value;

    if (!name || !age || !priority || !reg) {
        alert("Please fill in the required fields.");
        return;
    }

    let diseaseName = diseases[priority] || "Unknown Disease";

    let patient = {
        name,
        age,
        address,
        phone,
        bloodgroup,
        reg,
        priority: parseInt(priority),
        diseaseName
    };

    patients.push(patient);
    patients.sort((a, b) => a.priority - b.priority); // Sort by priority
    displayPatients();
    
    document.getElementById("name").value = "";
    document.getElementById("age").value = "";
    document.getElementById("address").value = "";
    document.getElementById("phone").value = "";
    document.getElementById("bloodgroup").value = "";
    document.getElementById("reg").value = "";
    document.getElementById("priority").value = "";
}

function deletePatient() {
    if (patients.length === 0) {
        alert("No patient records to delete!");
        return;
    }
    patients.shift(); // Remove first patient (highest priority)
    displayPatients();
}

function displayPatients() {
    let list = document.getElementById("patientList");
    list.innerHTML = "";

    patients.forEach((patient, index) => {
        let li = document.createElement("li");
        li.innerHTML = `
            <strong>Name:</strong> ${patient.name} <br>
            <strong>Age:</strong> ${patient.age} <br>
            <strong>Address:</strong> ${patient.address} <br>
            <strong>Phone:</strong> ${patient.phone} <br>
            <strong>Blood Group:</strong> ${patient.bloodgroup} <br>
            <strong>Reg No:</strong> ${patient.reg} <br>
            <strong>Priority:</strong> ${patient.priority} - ${patient.diseaseName} 
        `;
        list.appendChild(li);
    });
}

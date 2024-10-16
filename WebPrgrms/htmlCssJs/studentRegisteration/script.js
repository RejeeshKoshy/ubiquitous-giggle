document.getElementById('registrationForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent the form from submitting normally

    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const age = document.getElementById('age').value;
    const course = document.getElementById('course').value;

    // Simple validation check (just checking if fields are filled)
    if (name && email && age && course) {
        document.getElementById('successMessage').classList.remove('hidden');
    }
});
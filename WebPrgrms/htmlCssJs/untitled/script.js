// Get the form and the file input elements
const form = document.getElementById('registrationForm');
const fileUpload = document.getElementById('fileUpload');
const imgPreview = document.getElementById('imgPreview');

// Preview the uploaded image
fileUpload.addEventListener('change', function(event) {
	const file = event.target.files[0];
	if (file) {
		const reader = new FileReader();
		reader.onload = function(e) {
			imgPreview.src = e.target.result;
			imgPreview.style.display = 'block';
		};
		reader.readAsDataURL(file);
	} else {
		imgPreview.style.display = 'none';
	}
});


// Validate email address format
function validateEmail(email) {
	const re = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
	return re.test(email);
}

// Validate phone number format (simple example)
function validatePhoneNumber(phone) {
	const re = /^[0-9]{10}$/;
	return re.test(phone);
}

// Add custom validation logic
form.addEventListener('submit', function(event) {
	// Custom validation logic can go here
	if (!validateEmail(document.getElementById('email').value)) {
		alert('Please enter a valid email address.');
		event.preventDefault();
	}

	if (!validatePhoneNumber(document.getElementById('phone').value)) {
		alert('Please enter a valid phone number.');
		event.preventDefault();
	}
});


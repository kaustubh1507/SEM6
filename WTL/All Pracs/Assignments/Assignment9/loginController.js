// loginController.js
app.controller('LoginController', function ($scope, $location) {
    $scope.login = function () {
        // Here you would typically send data to the server for authentication
        console.log('Logged in with:', $scope.username, $scope.password);
        // Redirect to a different page after successful login
    };
});

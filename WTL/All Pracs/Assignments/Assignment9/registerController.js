// registerController.js
app.controller('RegisterController', function ($scope, $location) {
    $scope.user = {};

    $scope.register = function () {
        // Here you would typically send data to the server for registration
        console.log('Registered user:', $scope.user);
        $location.path('/login');
    };
});

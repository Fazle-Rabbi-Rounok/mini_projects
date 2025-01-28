<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Create Database</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            font-family: "Arial", sans-serif;
            background: linear-gradient(120deg, #075e54, #128c7e);
            color: white;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            position: relative;
            /* Required for absolute positioning of the button */
        }

        .container {
            max-width: 800px;
            width: 90%;
            padding: 30px;

            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
            text-align: center;
            border: 1px solid rgba(255, 255, 255, 0.2);
            animation: fadeIn 1s ease-in-out;
        }


        h1 {
            font-size: 36px;
            margin-bottom: 30px;
            color: white;
            font-family: "Georgia", serif;
            font-weight: 700;
            letter-spacing: 1px;
            text-shadow: 1px 1px 5px rgba(0, 0, 0, 0.3);
        }
    </style>
</head>

<body>
    <div class="container">
        <?php
        if ($_SERVER['REQUEST_METHOD'] == 'POST') {
            // Database credentials
            $servername = "localhost";
            $username = "root";
            $password = "";
            $dbname = "shopping";
            $port = 3307;

            // Create connection
            $conn = new mysqli($servername, $username, $password, $dbname, $port);

            // Check connection
            if ($conn->connect_error) {
                die("Connection failed: " . $conn->connect_error);
            }

            // Get form data
            $name = $_POST['name'];
            $email = $_POST['email'];
            $age = $_POST['age'];

            // Use prepared statements to prevent SQL injection
            $stmt = $conn->prepare("INSERT INTO users (name, email, age) VALUES (?, ?, ?)");
            $stmt->bind_param("ssi", $name, $email, $age);

            if ($stmt->execute()) {
                echo '<div class="message">User Signup Successful !</div>';
            } else {
                echo "Error: " . $stmt->error;
            }

            // Close the statement and connection
            $stmt->close();
            $conn->close();
        }
        ?>
        <a href="http://localhost/exp/05_queries.html" class="go-home-button">Home</a>
    </div>
</body>

</html>
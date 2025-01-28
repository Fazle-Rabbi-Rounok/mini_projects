<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Insert Data</title>
    <style>
        table {
            width: 100%;
            border-collapse: collapse;
        }

        th,
        td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }

        th {
            background-color: #f2f2f2;
        }
    </style>
</head>

<body>
    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "shopping";
    $port = 3307;

    $conn = new mysqli($servername, $username, $password, $dbname, $port);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $sql = "INSERT INTO
        orders (user_id, product, amount)
    VALUES
        (1, 'Laptop', 1200.00),
        (2, 'Tablet', 250.00),
        (12, 'Phone', 800.00),
        (15, 'Monitor', 300.00),
        (7, 'Keyboard', 100.00),
        (4, 'Mouse', 50.00),
        (3, 'Headphones', 150.00),
        (9, 'Printer', 350.00)";

    if ($conn->query($sql) === TRUE) {
        echo '<div class="message">Data inserted successfully.</div>';
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
    ?>
    <a href="http://localhost/exp/04_initialtask.html" class="go-home-button">Home</a>
</body>

</html>
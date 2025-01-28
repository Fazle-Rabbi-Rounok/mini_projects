<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <style>
        .to {
            text-align: center;
            color: rgb(0, 0, 0);
            font-size: 50px;
            font-family: "Georgia", serif;
            max-width: 200px;
            padding: 14px;
            background: bisque;
            border-radius: 10px;
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.2);
            border: 2px solid rgb(7, 1, 0);
            margin: 0 auto 50px auto;
        }
    </style>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Display Form Data</title>

</head>

<body>

    <div>
        <p class="to">Select</p>
    </div>
    <div class="left-container">
        <p><b>Definition</b></p>
    </div>
    <p class="defination">
        Select is Used to retrieve data from one or more tables.
    </p>
    <div class="left-container">
        <p><b>Code</b></p>
    </div>
    <div>
        <pre class="code-box">
SELECT
        *
    FROM
        users;</pre>

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "shopping";  // Database name
        $port = 3307;  
        
        $conn = new mysqli($servername, $username, $password, $dbname, $port);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT id, name, email, age FROM users";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            echo "<table>
                <tr>
                    <th>ID</th>
                    <th>Name</th>
                    <th>Email</th>
                    <th>Age</th>
                </tr>";
            while ($row = $result->fetch_assoc()) {
                echo "<tr>
                    <td>{$row['id']}</td>
                    <td>{$row['name']}</td>
                    <td>{$row['email']}</td>
                    <td>{$row['age']}</td>
                </tr>";
            }
            echo "</table>";
        } else {
            echo '<div class="message">No data found</div>';
        }

        $conn->close();
        ?>
        <a href="http://localhost/exp/05_queries.html" class="go-home">Home</a>
    </div>
</body>

</html>
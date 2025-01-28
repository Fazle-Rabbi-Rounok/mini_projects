<!DOCTYPE html>
<html lang="en">

<head>
    <link rel="stylesheet" href="cs.css" />
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Dynamic WHERE Clause</title>
    <style>
        body {
            font-family: "Georgia", serif;
            background: linear-gradient(120deg,
                    #075e54,
                    #075e54);
            color: black;
            padding: 20px;
            margin: 0;
            display: flex;
            flex-direction: column;
            align-items: center;
            min-height: 100vh;
        }

        h2 {
            text-align: center;
            color: bisque;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.2);
            margin-bottom: 20px;
        }

        form {
            background: rgba(255, 255, 255, 0.45);
            padding: 20px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
            max-width: 600px;
            width: 100%;
            margin-bottom: 20px;
        }

        label {
            display: block;
            margin-top: 15px;
            font-weight: bold;
            color: black;
        }

        textarea {
            width: 95%;
            background-color: rgb(73, 73, 68);
            color: white;
            padding: 12px;
            margin-top: 8px;
            border: 1px solid #ddd;
            border-radius: 8px;
            font-size: 16px;
            font-family: "Courier New", monospace;
            transition: border-color 0.3s ease, box-shadow 0.3s ease;
        }

        textarea:focus {
            border-color: #6a11cb;
            outline: none;
            box-shadow: 0 0 8px rgba(106, 17, 203, 0.5);
        }

        button {
            width: 100%;
            margin-top: 20px;
            padding: 12px;
            background: linear-gradient(120deg,
                    rgb(6, 169, 150),
                    rgb(22, 236, 211));
            color: black;
            border: 2px solid rgb(7, 1, 0);
            border-radius: 8px;
            font-size: 18px;
            font-weight: bold;
            cursor: pointer;
            transition: background 0.3s ease, transform 0.2s ease;
        }

        button:hover {
            background: rgb(128, 253, 255);
            transform: translateY(-2px);
        }

        button:active {
            transform: translateY(0);
        }

        p {
            color: black;
            text-align: center;
        }

        .go-home-button {
            position: fixed;
            /* Fixed position */
            bottom: 20px;
            /* Distance from the bottom */
            right: 20px;
            /* Distance from the right */
            background: linear-gradient(to right, #ff6f00, #ff8f00);
            color: white;
            border: none;
            padding: 10px 20px;
            border-radius: 20px;
            font-size: 16px;
            font-weight: bold;
            cursor: pointer;
            transition: all 0.3s ease;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.2);
            text-decoration: none;
            /* Remove underline from link */
        }

        .go-home-button:hover {
            background: linear-gradient(to right, #ff8f00, #ffa726);
            box-shadow: 0 6px 15px rgba(0, 0, 0, 0.3);
            transform: translateY(-3px);
        }

        .go-home-button:active {
            background: linear-gradient(to right, #ff6f00, #ff8f00);
            transform: translateY(1px);
            box-shadow: 0 3px 7px rgba(0, 0, 0, 0.3);

        }
    </style>
</head>

<body>
    <h2>Dynamic Query</h2>

    <form method="POST">
        <label for="query">SQL Query</label>
        <textarea id="query" name="query" columns="5" rows="3" placeholder="sql query"></textarea><br />
        <button type="submit">Execute Query</button>
    </form>

    <?php
    // Database credentials
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "shopping";
    $port = 3307;

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname, $port);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $sql = $_POST['query']; // Get the SQL query from the form
    
        // Execute the query
        $result = $conn->query($sql);

        if ($result) {
            if ($result->num_rows > 0) {
                echo "<table>
                        <tr>
                            <th>User ID</th>
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
        } else {
            echo "<p>Error executing query: " . $conn->error . "</p>";
        }
    }

    $conn->close();
    ?>
    <a href="http://localhost/exp/07_thnks.html" class="go-home-button">END</a>
</body>

</html>
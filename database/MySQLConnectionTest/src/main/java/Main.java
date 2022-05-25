import java.sql.*;

public class Main {

    public static void test(){
        String server = "cs3743.fulgentcorp.com";  // change with data received in email
        String db = "ab_mgomez"; // change with data received in email
        String url = "jdbc:mysql://" + server + "/" + db;
        String user = "abc123"; // change with data received in email
        String password = "???"; // change with data received in email


        Connection myConn;

        try {
            myConn = DriverManager.getConnection(url, user, password);
            Statement myStmt = myConn.createStatement();
            String sql = "select * from Student";
            ResultSet rs = myStmt.executeQuery(sql);

            while (rs.next())
                System.out.println(rs.getString("studentNr"));

        } catch (SQLException throwables){
            throwables.printStackTrace();
        }
    }
    public static void main(String[] args) throws Exception {
        test();
    }

}

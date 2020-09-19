import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

class CopyFile {

    public static void main(String[] args) throws IOException {

	FileInputStream infile = null;
	FileOutputStream outfile = null;
        var scanner = new Scanner(System.in);

        try {

            System.out.print("Enter the name of the file to copy: ");
	    String filename = scanner.next();

            infile = new FileInputStream(filename);
	    
            outfile = new FileOutputStream("copy_"+filename);
   
            int ch;
            while ((ch = infile.read()) != -1) {
                outfile.write(ch);
            }

        } catch (IOException e) {

            System.out.println(e.getMessage());

        } finally {

            if (infile != null){
                infile.close();
                outfile.close();
            }
            scanner.close();
        }

    }
}

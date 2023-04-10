import java.util.Scanner;
 
 
public class Parity {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int b,k,i,c=0;
        b = input.nextInt();
        k = input.nextInt();
        
        int[] a = new int[k];
        for(i=0;i<k;i++){
            a[i]=input.nextInt();
            if(a[i]%2==1) c++;
        }
        if(b%2==0 && a[k-1]%2==0){
            System.out.println("even");
        }
        else if(b%2==0){
            System.out.println("odd");
        }
        
        else if(c%2==0){
            System.out.println("even");
        }
        else{
            System.out.println("odd");
        }
    }
}
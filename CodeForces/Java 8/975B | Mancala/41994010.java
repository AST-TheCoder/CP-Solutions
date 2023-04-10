/******************************************************/
/******************************************************/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         Al-Shahriar Tonmoy - Red_Sparkle         **/
/**  Department of Computer Science and Engineering  **/
/**               Barisal University                 **/
/**               It's time to bloom.                **/
/******************************************************/
/******************************************************/
 
//testprograms//
 
import java.util.Scanner;
 
public class TestProgram1 {
    public static void main(String[] args) {
        
        Scanner input=new Scanner(System.in);
        
        int[] arr=new int[14];
        long c=0,m=0;
        
        for(int i=0;i<14;i++){
            
            arr[i]=input.nextInt();
            
        }
        
        for(int i=0;i<14;i++){
            
            int x=arr[i];
            int div=x/14,rem=x%14;
            
            for(int j=(i+1)%14;j!=i;j=(j+1)%14){
                
                if(((arr[j]+div)+(rem>0?1:0))%2==0){
                    
                    c+=((arr[j]+div)+(rem>0?1:0));
                    
                }
                
                rem--;
                
            }
            
            if(div%2==0) c+=div;
            
            if(c>m) m=c;
            c=0;
            
        }
        
        System.out.println(m);
        
    }
}
 
/*****************  ALHAMDULILLAH  *****************/
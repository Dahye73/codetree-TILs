public class Main {
    public static void main(String[] args) {
        int a = 2, b = 5;
        int tmp;
        tmp = a;
        a = b;
        b = tmp;

        System.out.println(a);
        System.out.println(b);
    }
}
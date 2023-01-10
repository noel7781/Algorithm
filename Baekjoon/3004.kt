import java.util.Scanner
fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)
    var n = sc.nextInt()
    if (n % 2 == 1) {
        println((n/2 + 1) * (n/2 + 2))
    } else {
        println((n/2 + 1) * (n/2 + 1))
    }
}

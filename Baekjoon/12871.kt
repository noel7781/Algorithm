import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

fun gcd(a: Int, b:Int): Int = if(b != 0) gcd(b, a % b) else a

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val s1 = br.readLine()
    val s2 = br.readLine()

    val lcm = s1.length * s2.length / gcd(s1.length, s2.length)
    var str1 = s1 * (lcm / s1.length)
    var str2 = s2 * (lcm / s2.length)
    println("${if (str1 == str2) 1 else 0}")
}

private operator fun String.times(n: Int): String {
    val ret = StringBuilder()
    val tmp = this
    for (i in 0 until n) {
        ret.append(tmp)
    }
    return ret.toString()
}


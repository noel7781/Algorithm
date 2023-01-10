import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    var array = br.readLine().split(' ').map { it.toLong() }.toMutableList()
    var now = array.first()
    array[0] = 0
    array.sort()

    var result = "Yes"
    for (i in 0 until n) {
        if (now <= array[i]) {
            result = "No";
            break;
        }
        now += array[i]
    }
    println(result)
}

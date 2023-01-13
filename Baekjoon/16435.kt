import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, L) = br.readLine().split(' ').map { it.toInt() }
    val heights = br.readLine()
        .split(' ')
        .map { it.toInt() }
        .sorted()

    var result = L
    for (i in 0 until N) {
        if (result >= heights[i]) {
            result += 1
        }
    }
    println("$result")

}

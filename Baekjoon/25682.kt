import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, M, K) = br.readLine().split(' ').map{ it.toInt() }
    var board = ArrayList<String>()
    repeat(N) {
        val row = br.readLine()
        board.add(row)
    }
}

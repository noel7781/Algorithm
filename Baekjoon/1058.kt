import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val friends = mutableListOf<MutableList<Int>>()
    val dists = Array(N) { IntArray(N) {1e9.toInt()} }
    repeat(N) {
        val rows = br.readLine()
            .toCharArray()
            .map { if (it == 'N') 0 else 1 }
            .toMutableList()
        friends.add(rows)
    }
    for (i in 0 until N) dists[i][i] = 0
    for (i in 0 until N) {
        for (j in 0 until N) {
            if (friends[i][j] == 1) dists[i][j] = 1
        }
    }

    for (k in 0 until N) {
        for (i in 0 until N) {
            for (j in 0 until N) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j])
            }
        }
    }
    var res = 0
    for (i in 0 until N) {
        res = max(res, dists[i].toList().stream().filter { it in 1..2 }.count().toInt())
    }
    println("$res")
}
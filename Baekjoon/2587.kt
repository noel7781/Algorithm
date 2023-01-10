import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var list = ArrayList<Int>()
    for (i in 1..5) {
        list.add(br.readLine().toInt())
    }
    list.sort()
    println(list.average().toInt())
    println(list.get(2))
}

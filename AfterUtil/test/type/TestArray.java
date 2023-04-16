package type;


import org.junit.Test;
import util.Calculator;
import util.FileUtil;


import java.io.IOException;
import java.lang.reflect.AnnotatedArrayType;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TestArray {

    @Test
    public void testSortedMathQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\Math\\math.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\Math\\math_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links_array = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links_array.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links_array.size(); i++) {
            String[] temp = links_array.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);


    }

    @Test
    public void testSortedArrayQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\Array\\array.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\Array\\array_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links_array = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links_array.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links_array.size(); i++) {
            String[] temp = links_array.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

    @Test
    public void testSortedStringQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\String\\string.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\String\\string_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }

    @Test
    public void testSortedHashTableQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\HashTable\\hash_table.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\HashTable\\hash_table_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

    @Test
    public void testSortedBinaryTreeQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\BinaryTree\\binary_tree.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\BinaryTree\\binary_tree_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

    @Test
    public void testSortedDynamicQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\DynamicProgramming\\dynamic.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\DynamicProgramming\\dynamic_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }

    @Test
    public void getSortedSortingQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\Sorting\\sort.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\Sorting\\sort_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

    @Test
    public void getSortedMatrixQuestion() throws IOException {

        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\Matrix\\matrix.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\Matrix\\matrix_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

    @Test
    public void testSortedBinarySearchQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\BinarySearch\\binary_search.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\BinarySearch\\binary_search_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }


    @Test
    public void getSortedGreedyQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\Greedy\\greedy.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\Greedy\\greedy_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }

    @Test
    public void getSortedDFSQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\DFS\\dfs.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\DFS\\dfs_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);
    }

    @Test
    public void getSortedBFSQuestion() throws IOException {
        String allLinksPath = "D:\\CopilotTest\\type_analysis\\allLinks.txt";
        String linksPath = "D:\\CopilotTest\\type_analysis\\BFS\\bfs.txt";
        String resPath = "D:\\CopilotTest\\type_analysis\\BFS\\bfs_res.txt";
        List<String> links_all = FileUtil.getStringListFromFile(allLinksPath);
        List<String> links = FileUtil.getStringListFromFile(linksPath);
        List<String> res_list = new ArrayList<>();

        System.out.println("All Question num:" + links_all.size());
        System.out.println("Question num:" + links.size());

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < links.size(); i++) {
            String[] temp = links.get(i).split("\t");
            map.put(temp[0], temp[1]);
        }

        System.out.println(map.size());

        for (int i = 0; i < links_all.size(); i++) {
            int index = i + 1;
            String link = links_all.get(i).substring(0, links_all.get(i).length() - 1);
            String pattern = null;
            if (index >= 1 && index <= 120)
                pattern = "Easy";
            if (index > 120 && index <= 630)
                pattern = "Medium";
            if (index > 630 && index <= 990)
                pattern = "Hard";
            if (map.containsKey(link)) {
                String str = String.valueOf(index) + "\t" + link + "\t" + map.get(link) + "\t" + pattern;
                res_list.add(str);
                map.remove(link);
            }
        }
        System.out.println(map.size());
        System.out.println(map);
        FileUtil.writeStringtoFile(resPath, res_list);

    }

    @Test
    public void testRatePercent()
    {
        System.out.println(Calculator.calculateTripple(65,16,81));

    }

}




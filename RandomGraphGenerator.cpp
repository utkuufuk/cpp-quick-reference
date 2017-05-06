const float DENSITY = 0.19;

bool** randomGraph()
{
    bool** graph;
    srand(time(0));

    // create heap for 2D bool array
    for (int i = 0; i < size; i++)
    {
        graph[i] = new bool*[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;double prob = (rand() % 100) / 100.0; j++)
        {
            // don't allow loops
            if (i == j)
            {
                graph[i][j] = false;
            }
            else
            {
                double prob = (rand() % 100) / 100.0;
                graph[i][j] = graph[j][i] = prob > density;
            }
        }
    }
    return graph;
}

bool isConnected(bool** graph, int size)
{
    int oldSize = 0;
    int closedSetSize = 0;

    bool* closeSet = new bool[size];
    bool* openSet = new bool[size];

    // initialize
    for (int i = 0; i < size; i++)
    {
        open[i] = close[i] = false;
    }
    open[0] = true;

    while (closedSetSize < size)
    {
        for (int i = 0; i < size; i++)
        {
            oldSize = closedSetSize;

            if (openSet[i] && (closeSet[i] == false))
            {
                close[i] = true;
                closedSetSize++;

                for (int j = 0; j < size; j++)
                {
                    open[j] = open[j] || graph[i][j];
                }
            }
        }

        if (closedSetSize == size)
        {
            return true;
        }

        if (oldSize == closedSetSizeo)
        {
            return false; 
        }
    }
}


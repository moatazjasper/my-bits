/* Description:
 * This function performs circular shift on an array
 *         of a given size in O(n) speed.
 * For Right Shifting (>>), make "shifts" variable +ve .
 * For Left  Shifting (<<), make "shifts" variable -ve .
 */
void circ_shift(long long* array, const long long size, long long shifts)
{
    long long len, i, j;

    //cut extra shift
    shifts %= size;

    //if shift is less then 0 - redirect shifting left
    if ( shifts < 0 )
    {
        shifts += size;
    }

    len = size - shifts;

    //choosing the algorithm which needs less memory
    if ( shifts < len )
    {
        //creating temporary array
        long long tmpArray[shifts];

        //filling tmp array
        for (i = 0, j = len; i < shifts; i++, j++ )
        {
            tmpArray[i] = array[j];
        }

        //shifting array
        for (i = size - 1, j = i - shifts; j >= 0; i--, j-- )
        {
            array[i] = array[j];
        }

        //inserting lost values from tmp array
        for (i = 0; i < shifts; i++ )
        {
            array[i] = tmpArray[i];
        }
    }
    else
    {
        //creating temporary array
        long long tmpArray[len];

        //filling tmp array
        for (i = 0; i < len; i++ )
        {
            tmpArray[i] = array[i];
        }

        //shifting array
        for (i = 0, j = len; j < size; i++, j++ )
        {
            array[i] = array[j];
        }

        //inserting lost values from tmp array
        for (i = shifts, j = 0; i < size; i++, j++ )
        {
            array[i] = tmpArray[j];
        }
    }
}

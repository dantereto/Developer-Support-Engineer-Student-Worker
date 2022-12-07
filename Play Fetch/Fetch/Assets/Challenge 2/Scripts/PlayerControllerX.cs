using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControllerX : MonoBehaviour
{
    public GameObject dogPrefab;
    public float timeBetween = 0.9f;
    private float timestamp;

    // Update is called once per frame
    void Update()
    {
        // On spacebar press, send dog
        if (Time.time >= timestamp &&  (Input.GetKeyDown(KeyCode.Space)))
        {
            Instantiate(dogPrefab, transform.position, dogPrefab.transform.rotation);
            timestamp = Time.time + timeBetween;
        }
    }
}
